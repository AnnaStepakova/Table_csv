# Table_csv
Define a table from csv file and compute lacking values

Package build status on Travis CI: [![Build Status](https://travis-ci.org/AnnaStepakova/Table_csv.png?branch=main)](https://travis-ci.org/AnnaStepakova/Table_csv)

Мы можем во время парсинга запоминать ячейки, требующие вычислений.
Это означает более быстрое вычисление ценой расхода памяти O(количество ячеек).
Можем идентифицировать такие ячейки в пост-процессинге. Это потенциально увеличивает
время работы (если всего ячеек много, а ячеек для вычисления мало), но не требует
дополнительной памяти.

Я выбрала подход, при котором ячейки, требующие вычисления, идентифицируются в пост-процессинге.
