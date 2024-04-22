#!/bin/bash
id -Gn $FT_USER | sed 's/ /,/g' | xargs echo -n
