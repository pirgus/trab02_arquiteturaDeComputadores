echo "Cleaning executables..."
make clean
echo "Recompiling..."
make

executables=("bucket_seq.x" "bucket_par.x")
sizes=("250000" "500000" "750000" "1000000")
out_files=("in250k.txt" "in500k.txt" "in750k.txt" "in1m.txt")

for ((i=0; i<${#sizes[@]}; i++)) do
	echo "Generating ${sizes[$i]} entry file..."
	./gera_lista.x ${sizes[$i]} ${out_files[$i]}
done

for executable in "${executables[@]}"; do
	for entry in "${out_files[@]}"; do
		echo "Executing $executable for $entry"
		./$executable $entry
	done
done

#rm *.txt
