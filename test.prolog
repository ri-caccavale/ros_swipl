male(adam).
male(bill).
male(carl).

female(dory).
female(elen).
female(fanny).

father(adam,bill).
father(adam,elen).

mother(dory,bill).
mother(dory,elen).

mother(elen,carl).

% Horn clause
% B1 and B2 and ... and Bn -> H

daughter(X,Y):-
	mother(Y,X),
	female(X).
	
daughter(X,Y):-
	father(Y,X),
	female(X).
	
son(X,Y):-
	mother(Y,X),
	male(X).
	
son(X,Y):-
	father(Y,X),
	male(X).
	
% examples:
%	daughter(X,adam). -> X will be unified with a daughter of adam -> X is elen
%	son(X,adam). -> X will be unified with a son of adam -> X is bill
%	son(X,elen). -> false.

anchestor(X,Y):-
	mother(X,Y).
	
anchestor(X,Y):-
	father(X,Y).
	
anchestor(X,Y):-
	mother(X,Z),
	anchestor(Z,Y).
	
anchestor(X,Y):-
	father(X,Z),
	anchestor(Z,Y).
