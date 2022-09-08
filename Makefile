

# Run doxygen on the src file and create a symlink of the 
# "index.html" in the "doc" directory
doc:
	doxygen Doxyfile
	ln -s "$(PWD)/doc/html/index.html" "$(PWD)/doc"

