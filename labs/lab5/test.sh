#!/bin/bash
echo "TESTS TÂCHE 3"
for i in {1..8}
do
  ./lab5 < "test/test$i.txt" > "test/test$i.monresultat.txt"
  diff "test/test$i.monresultat.txt" "test/test$i-result.txt"
done
echo "FIN TESTS TÂCHE 3"
