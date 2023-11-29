#!/bin/bash

make 

input_file="red.bin"
output_file="RED.txt"

# Encode binary file to base64 and save the result in the output file
base64 "$input_file" > "$output_file"

make clean

echo "Conversion complete. Base64 output saved to '$output_file'."
