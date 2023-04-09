# Programmed By Sravanth Chowdary Potluri CS20B1006
import pytholog as pl

new_kb = pl.KnowledgeBase("lab_RR")

# passing the rules and facts into the knowledge base
new_kb(["child_loves(X) :- child(X), loves(X, santa).",
        "loves(X, santa) :- child(X).",
        "loves(X, Y) :- loves(X, santa), reindeer(Y).",
        "reindeer(rudolph).",
        "has_red_nose(rudolph).",
        "weird(X) :- has_red_nose(X) ; clown(X).",
        "not(clown(X)) :- reindeer(X).",
        "not_loves_scrooge(X) :- scrooge(Y), weird(X), loves(Y, X).",
        "scrooge(scrooge)."])

# asking a query, and printing the results obtained after logical inference
print("Is Scrooge a Child?: " + str(new_kb.query(pl.Expr("not(child(scrooge))"))[0]))