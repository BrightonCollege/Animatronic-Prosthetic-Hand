#!/bin/bash
#WARNING: This script is not tested. (And it is unlikely to work)
if [[ "`which bluez-simple-agent`" == "" ]]; then
    echo "This script requires bluez-simple-agent to be installed in \$PATH"
    exit
fi
if [[ "$1" == "pair" ]]; then
    echo "Please enter PIN code 1234"
    bluez-simple-agent hci0 00:06:66:66:25:EB
fi
sudo rfcomm bind 00:06:66:66:25:EB 4
exec 3<>/dev/rfcomm4
echo -n '$$$' > &3
echo 'U,9600,N' > &3
cat < &3 &
while read i; do
    echo -n "$i" > &3
done
kill $!
