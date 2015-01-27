# To run, start gnuplot in a terminal window. At the prompt, type: load "./gnuPlotSample"

reset

file1 = "./solution.dat0"
file1legend = "file1Legend"
set style line 1 lt 1 lc rgb "#CC0000" lw 1 pt 2 ps 0.2 # define line style 1 (line type, line colour, line width, point type, point size)

xtitle = "x"
ytitle = "y"

set xlabel xtitle
set ylabel ytitle

# to simply plot to screen

plot file1 u 1:2 title file1legend w points ls 1

# to save instead as a pdf file

#set terminal pdf enhanced
#set output "test.pdf"

#plot file1 u 1:2 title file1legend w points ls 1, file2 u 1:2 w lines title file2legend ls 2

#unset output
