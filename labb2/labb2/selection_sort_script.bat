set  terminal  pdf  font "cmr"
set  output  "selectionSortDesc.pdf"
#set  size 1,2
set  key box
#set  samples 50, 50
#set  style  data  lines
set  title "std::sort  -- Decreasing series"
set  xlabel "N elements"
set  ylabel "t [ms]"
x = 0
f(x) = a*x**2
f1(x) = a1*x*log(x)/log(2)
fit [1000:10000][0:2000] f(x) "selection_sort.txt" via a plot "C:\\Users\\Tiimm\\Documents\\Plugg and stuff\\labb2_dt046g\\labb2\\labb2\\selection_sort.txt" title "Decreasing input" with  errorbars , f(x) smooth  csplines t "Fit k N^2"
#close  output  file
set  output
set  terminal  pop