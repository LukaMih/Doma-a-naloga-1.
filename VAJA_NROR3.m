(* ::Package:: *)

(* ::Input:: *)
(*f[t_]:=Sin[t] t^2 Exp[-t]*)
(**)
(*TaylorApproximation[n_Integer,t_]:=Normal[Series[f[t],{t,2,n}]]*)
(**)
(**)


(* ::Input:: *)
(*Manipulate[*)
(*Plot[*)
(*{f[t],TaylorApproximation[n,t]},{t,0,4},*)
(*PlotLegends->{"funkcija","Pribli\[ZHacek]ek "<>ToString[n]<>". reda"}],*)
(*{{n,5,"Red pribli\[ZHacek]ka"},1,10,1}]*)



