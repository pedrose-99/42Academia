#!/bin/bashe 
cat /etc/passwd | sed -e '/#/d' | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | sed -n "$FT_LINE1","$FT_LINE2"p | tr '\n' ' ' | sed 's/ /, /g' | sed "s/..$/./g" | sed 's/\n//g' | tr -d '\n'


