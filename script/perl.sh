if [ -z "$1" ]; then
  LENGTH=20
else
  LENGTH=$1
fi

SALT="[ENTER YOUR SALT HERE]"
START=$((${#SALT} + 5))
END=$(($START + $LENGTH - 1))

read -s -p "Password: " PASS
echo ""
perl -e "print crypt('$PASS', '\$6\$$SALT\$')" | cut -c $START-$END
