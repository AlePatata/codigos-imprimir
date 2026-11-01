#set page(
  paper: "a4"
)

#set text(
  font: "New Computer Modern",
  size: 13pt
)

#show link: set text(size: 8pt)
#show link: underline

// Portada
#[
  #set align(center + horizon)
  #image("img/ranita.png")
  #text(size: 2.5em)[Apunte popcorn]

  #if "version" in sys.inputs [Versión #sys.inputs.version]

  #text(size: 8pt)[
    Basado en el Handbook de los estudiantes de la Universidad Técnica Federico Santa María,
    disponible en Github: ProgramacionCompetitivaUTFSM/Handbook-USM
    #footnote(link("https://github.com/ProgramacionCompetitivaUTFSM/Handbook-USM"))
  ]
]

// Índice
#pagebreak()
#[
  #set page(columns: 2)
  #set text(size: 10pt)
  #outline(title: [Índice])
]
#pagebreak()

// Content
#include "content.typ"
