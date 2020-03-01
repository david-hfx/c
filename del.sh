find . -name "*.out" -exec rm -f {} \;

find . -name "*.exe" -exec rm -f {} \;

find . -name "*.o" -exec rm -f {} \;

ls | grep -P "^([^.]+)$" | xargs -d"\n" rm
