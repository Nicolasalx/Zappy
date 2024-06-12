#!/bin/bash

for file in *.jpg *.jpeg; do
    [ -e "$file" ] || continue
    
    newfile="${file%.*}.png"

    convert "$file" "$newfile"

    if [ $? -ne 0 ]; then
        echo "Failed to convert $file"
    else
        echo "Converted $file to $newfile"
    fi
done
