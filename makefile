violeta.pdf: datos.txt
	python violeta.py
	rm violeta.rs datos.txt

datos.txt: violeta.rs
	./violeta.rs > datos.txt

violeta.rs:
	c++ violeta.cpp -o violeta.rs
