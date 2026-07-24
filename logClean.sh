#!/bin/bash

sed -Ei '
/^#/d;
s/HTTP\/1\.0/HTTP\/1.1/g
s/[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}/XXXX-XXXX-XXXX-XXXX/g
s/[0-9]{16}/XXXX-XXXXX-XXXX-XXXX/g
' server_access.log
