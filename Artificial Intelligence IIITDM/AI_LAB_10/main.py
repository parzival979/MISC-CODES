import pytholog as pl

kb = pl.KnowledgeBase("facts")

kb(["likes(shyam, mango)", "girl(seema)","red(rose)", "likes(bill, cindy)","owns(john ,gold)"])

what = "mango"

print("?- likes (shyam, What)")
print(kb.query(pl.Expr("likes(shyam, " + str(what) + ")")))