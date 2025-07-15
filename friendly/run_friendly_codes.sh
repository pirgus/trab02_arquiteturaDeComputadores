#!/bin/bash
make
# Lista de entradas para os programas friendly_*
inputs=("250000" "500000" "750000" "1000000")

# Executa friendly_seq.x e friendly_par.x com entradas
for exe in "friendly_seq" "friendly_par"; do
    echo "Executando $exe com diferentes entradas..."
    for value in "${inputs[@]}"; do
        echo "Entrada: 1 $value"
        #for i in {1..10}; do
        #    echo "Execução $i:"
        echo -e "1 $value\n0 0" | ./$exe
        #done
        echo ""
    done
    echo ""
done

