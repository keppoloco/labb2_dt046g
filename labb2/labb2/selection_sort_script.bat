cd "C:\\Users\\Tiimm\\Documents\\Plugg and stuff\\labb2_dt046g\\labb2\\labb2"

set  terminal  pdf  font "cmr"
set  output  "Standardsort_random_values.pdf"
set key autotitle columnhead
#set  size 1,2
set  key box
#set  samples 50, 50
set  terminal  pdf  font "cmr"
set  output  "Standardsort_random_values.pdf"
#set  size 1,2
set  key box
#set  samples 50, 50
#set  style  data  lines
set  title "std::sort  -- Random series"
set  xlabel "N elements"
set  ylabel "t [ms]"
x = 0
f(x) = a*x**2
f1(x) = a1*x*log(x)/log(2)
fit [1000:10000][0:2000] f(x) "selectionSort.data" via a
plot "selectionSort.data" title "Random input" with  errorbars , f(x) smooth  csplines t "Fit k N^2"
#close  output  file
set  output
set  terminal  pop


#set  style  data  lines
set  title "std::sort  -- Random series"
set  xlabel "N elements"
set  ylabel "t [ms]"
x = 0
f(x) = a * (x*log(x)) + b
fit [1000:10000][0:2000] f(x) "selection_sort.data" via a plot "C:\\Users\\Tiimm\\Documents\\Plugg and stuff\\labb2_dt046g\\labb2\\labb2\\selection_sort.txt" title "Random input" with  errorbars , f(x) smooth  csplines t "Fit k N^2"
#close  output  file
set  output
set  terminal  pop



## SELECTION SORT RANDOM VALUES ##
set terminal pdf font 'cmr'
set output 'Standardsort_constants_values.pdf'
#set size 1,2
set key autotitle columnhead
#set samples 50, 50
#set style data lines
set title "std::sort -- Constant series"
set xlabel "N elements"
set ylabel "t [{/Symbol m}s]"
x = 0.0

plot "selection_sort.data" title "Random input" with errorbars, "fit.dat" smooth csplines t "Fit k N^2"
#close output file
set output
set terminal pop


set  terminal  pdf  font "cmr"
set  output  "Standardsort_decreasing_values.pdf"
set key autotitle columnhead
datafile = 'standard_sort.data'
set xrange [300:4500]
set key autotitle columnhead
f(x) = a * (x*log(x)) + b
plot "standard_sort.data" using 1:2 title "Decreasing input" with errorbars
set output
set terminal pop