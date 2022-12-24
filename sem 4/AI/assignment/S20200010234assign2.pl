spouse(mary, john).
spouse(carl, janet).
gender(mary, female).
gender(john, male).
gender(carl, male).
gender(janet, female).

isWife(X) :- spouse(X,Y), gender(X,female).
isWife(X) :- spouse(Y,X), gender(X,female).

gender(yash, male).
gender(rashi, female).
gender(mansi, female).
gender(alok, male).
gender(mala, female).
gender(kailash, male).
gender(dadi, female).
gender(richa, female).
gender(anil, male).
spouse(alok, mala).
spouse(mala, alok).
spouse(kailash, dadi).
spouse(dadi, kailash).
parent(alok, yash).
parent(alok, rashi).
parent(alok, mansi).
parent(mala, yash).
parent(mala, rashi).
parent(mala, mansi).
parent(kailash, alok).
parent(dadi, alok).
parent(anil, richa).
sibling(yash, rashi).
sibling(yash, mansi).
sibling(rashi, mansi).
sibling(rashi, yash).
sibling(alok, anil).
sibling(anil, alok).

father(X,Y) :- parent(X,Y), gender(X, male).
mother(X,Y) :- parent(X,Y), gender(X, female).
siblings(X,Y) :- sibling(X,Y), sibling(Y,X).
descendant(X,Y) :- parent(Y,X); (parent(Y,Z), descendant(X,Z)).
firstcousin(X,Y) :- parent(A,X), parent(B,Y), siblings(A,B).
