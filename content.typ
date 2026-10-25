#import "lib/hash.typ": md5, hex

#set page(
  paper: "a4",
  columns: 2,
  margin: (x: 2em, y: 2em),
  numbering: "1/1"
)

#set text(
  font: "New Computer Modern",
  size: 7pt
)

// Los nombres de archivo van sin tildes; acá se agregan para el título
#let accents = (
  area: "área", arbol: "árbol", busqueda: "búsqueda", calculo: "cálculo",
  depuracion: "depuración", dinamico: "dinámico", ejecucion: "ejecución",
  factorizacion: "factorización",
  funcion: "función", geometria: "geometría", minima: "mínima",
  minimos: "mínimos", numeros: "números", poligono: "polígono",
  rotacion: "rotación", topologico: "topológico", trigonometria: "trigonometría",
)
// Conectores que quedan en minúscula (salvo al inicio)
#let small-words = ("y", "de", "del", "en", "la", "el", "a")
// Siglas que van en mayúscula
#let acronyms = ("dfs", "bfs", "lca", "hld", "ahld", "kmp", "lis", "vim", "2d", "stl")

#let title-case(string) = {
  if string.len() <= 3 {
    return upper(string)
  }

  let first = true
  let words = ()
  for word in string.split(" ") {
    let w = accents.at(lower(word), default: word)
    if lower(w) in acronyms {
      words.push(upper(w))
    } else if not first and lower(w) in small-words {
      words.push(lower(w))
    } else {
      words.push(upper(w.first()) + lower(w.slice(w.first().len())))
    }
    first = false
  }
  words.join(" ")
}

#let content-to-string(content) = {
  if content.has("text") {
    content.text
  } else if content.has("children") {
    content.children.map(content-to-string).join("")
  } else if content.has("body") {
    content-to-string(content.body)
  } else if content == [ ] {
    " "
  }
}

#let get-code-hash(string) = {
  string = string.replace(regex("[\n\t\s]"), "")
  hex(md5(string)).slice(0, 6)
}

#let comments-regex = regex("\/\*[\s\S]*?\*\/")

#let get-description-from-code(string) = {
  let comments = string.find(comments-regex)

  if type(comments) != str or string.trim().at(0) != "/" {
    //return "#text(red)[*You must provide a description for each template code!*]"
    return "_Sin descripción._"
  }

  let lines = comments.split("\n")
  lines.slice(1, lines.len() - 1)
    .map(it => if it.ends-with("\\") {
      it.trim("\\", at: end)
    } else {
      it + "\\"
    })
    .join().trim()
}

#let remove-description-from-code(string) = {
  if string.trim().at(0) != "/" {
    return string
  }
  string.replace(comments-regex, "", count: 1).trim()
}

#let template-code(title: [], only-code: [], level: 2, body) = {
  let code-lines = only-code.split("\n").len()
  let text-size = if code-lines > 90 { 5.3pt } else { 7pt }

  block(
    breakable: false,
    radius: 5pt,
    inset: 1em,
    stroke: 0.9pt,
    spacing: 1.5em,
    width: 100%,
  {
    place(dy: -15pt, dx: 220pt, block(fill: black, inset: 3pt, {
      text(fill: green)[\#]
      text(fill: white, weight: "semibold", get-code-hash(only-code))
    }))

    place(dy: -15pt, block(fill: black, inset: 3pt, {
      show heading: set text(fill: white, weight: "semibold")
      heading(level: level, title)
    }))

    set text(size: text-size)
    body
  })
}

#let template-category-title(title) = {
  block(spacing: 1.5em, {
    show heading: set text(weight: "black", size: 18pt)
    heading(title)
    v(-0.5em)
    line(length: 100%, stroke: 1.5pt)
  })
}

#let template-subcategory-title(title) = {
  block(spacing: 1em, sticky: true, {
    show heading: it => [
      #set text(weight: "black", size: 12pt, fill: rgb("#444"))
      #sym.triangle.filled.r~#it.body
    ]
    v(-0.3em)
    heading(depth: 2, title)
    v(0.2em)
  })
}

#let template-section-title(title) = {
  show heading: set text(weight: "black", size: 15pt)
  heading(title)
  v(3pt)
}

#let typst-section(title: [], content: [], level: 2) = {
  block(
    breakable: false,
    inset: 1em,
    stroke: 0.9pt,
    spacing: 2em,
    width: 100%,
  {
    {
      show heading: set text(weight: "bold", size: 10pt)
      align(center, heading(level: level, title))
    }

    set heading(offset: level)
    eval(content, mode: "markup")
  })
}

#let render-file(path, file-name, level: 2) = {
  let file-extension = path.split(".").at(-1)
  let template-title = title-case(file-name.split(".").at(0).split("-").join(" "))
  let file = read(path)

  if file-extension == "typ" {
    typst-section(title: template-title, content: file, level: level)
  } else if file-extension == "cpp" {
    let all-code = raw(file, lang: "cpp")
    let comments = get-description-from-code(content-to-string(all-code))
    let without-comments = remove-description-from-code(content-to-string(all-code))

    template-code(title: template-title, only-code: without-comments, level: level, {
      eval(comments, mode: "markup")
      line(length: 100%)
      raw(without-comments, lang: "cpp")
    })
  }
}

#for x in yaml("tracker.yaml") {
  let content-list = x.at(1)
  for i in range(0, content-list.len()) {
    let topic-entry = content-list.at(i)
    for (topic-name, items) in topic-entry {
      // Show main category title
      let category-title = title-case(topic-name.split("-").join(" "))
      template-category-title(category-title)

      for item in items {
        if type(item) == str {
          // Direct file in topic (no subtopic)
          let path = "content/" + topic-name + "/" + item
          render-file(path, item)
        } else if type(item) == dictionary {
          // Subtopic with files
          for (subtopic-name, files) in item {
            let subcategory-title = title-case(subtopic-name.split("-").join(" "))
            template-subcategory-title(subcategory-title)
            for file-name in files {
              let path = "content/" + topic-name + "/" + subtopic-name + "/" + file-name
              render-file(path, file-name, level: 3)
            }
          }
        }
      }
    }
    if i != content-list.len() - 1 {
      pagebreak()
    }
  }
}
