## Erklären Sie in einem kurzen Kommentar den Unterschied zwischen `square(3)` und `square<int>(3)`.
Bei `square<int>(3)` wird der Typ "T" explizit festgelegt.
Bei `square(3)` bestimmt der Compiler den Typ "T" automatisch anhand des Parameters.
## Erklären Sie in einem kurzen Kommentar, warum der add-Aufruf für std::string ohne weitere Änderung funktioniert. Committen Sie Ihre Änderungen.
Der Grund dafür ist, dass +-Operation auch für std::string definiert ist. Es gibt aber eine semantische Differenz. +-Operation fügt 2 Strings zusammen.