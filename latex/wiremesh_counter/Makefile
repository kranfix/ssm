clean: cleanlog cleanb
	rm *.log
	rm *.synctex.gz
	rm *.aux

cleanpdf:
	rm *.pdf

cleanlog:
	rm *.log

cleanb: *.bbl *.blg
	rm $^

cleanall: clean cleanpdf
