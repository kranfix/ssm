clean: cleancomp cleanb
	rm *.log
	rm *.synctex.gz
	rm *.aux

cleancomp: *.log *.synctex.gz *.aux
cleanpdf: *.pdf
cleanb: *.bbl *.blg
	rm $^

cleanall: clean cleanpdf
