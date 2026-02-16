set title 'Kütle Yay'
set xlabel 'Zaman(t) saniye'
set ylabel 'Genlik (Hız ve Konum)'
plot 'kutleyay.txt' using 1:2 with linespoints linewidth 0.5 pointtype 0 title 'Hiz (V)', '' using 1:3 with linespoints linewidth 0.5 pointtype 0 title 'Konum (X)'
pause -1
