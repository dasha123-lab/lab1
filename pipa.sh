#!/bin/bash
printArray() {
  local arr=("$@")
  local n=${#arr[@]}
    for ((i=0; i<n; i++)); do
       for ((h=i+1; h<n; h++)); do
          if [[ "${arr[i]}" == "${arr[h]}" ]]; then
            echo "Есть дубликат"
            return 1
            fi
        done
   done
     echo "Элементы уникальны"
   return 0
  }
printArray "$@" 
