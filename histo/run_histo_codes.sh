echo "Cleaning executables..."
make clean
echo "Recompiling..."
make

executables=("histogram_seq.x" "histogram_par.x")
sizes=("2500000" "5000000" "7500000" "10000000")
out_files=("in2-5m.txt" "in5m.txt" "in7-5m.txt" "in10m.txt")

for ((i=0; i<${#sizes[@]}; i++)) do
        echo "Generating ${sizes[$i]} entry file..."
        ./gera_lista.x ${sizes[$i]} ${out_files[$i]}
done

for executable in "${executables[@]}"; do
        for ((i=0; i<${#out_files[@]}; i++)); do
                echo "Executing $executable for ${sizes[$i]}"
		echo "./$executable ${sizes[$i]} ${out_files[$i]}"
                ./$executable ${sizes[$i]} ${out_files[$i]}
        done
done

#rm *.txt

