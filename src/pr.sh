rm -f out.txt
for f in *[ph] ; do
  echo >>out.txt
  echo "=========================================================================" >>out.txt
  echo $f >>out.txt
  echo "=========================================================================" >>out.txt
  nl $f >>out.txt
done
