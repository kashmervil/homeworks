data Expr = C Int
           |Var
           |Add Expr Expr
           |Mul Expr Expr
           |Pow Expr Int
           deriving (Show)
infixl 3 .+

e1 .+ e2 = Add e1 e2

infixl 4 .-

e1 .- e2 = Add e1 ((C (-1)) .* e2)

infixl 5 .*

e1 .* e2 = Mul e1 e2

infixl 5 ./

e1 ./ e2 = Mul e1 (e2 .^ (-1))

infixr 8 .^

e1 .^ k = Pow e1 k

(!) :: Expr -> Expr

(!) (C _) = C 0

(!) Var   = C 1

(!) (Add e1 e2) = ((!) e1) .+ ((!) e2)

(!) (Mul e1 e2) =  ((!) e1) .* ((!) e2)  .+  ((!) e1) .* ((!) e2)

(!) (Pow e1 k)  =  (C k) .* e1 .^ (k-1) .* ((!) e1)
simplyfy :: Expr -> Expr
simplyfy (Add (C x) (C y)) = C (x+y)
simplyfy (Mul (C x) (C y)) = C (x*y)
simplyfy (Pow (C x) k)     = C (x^k)
simplyfy (Add x (C 0))     = simplyfy x
simplyfy (Add (C 0) x)     = simplyfy x
simplyfy (Mul x (C 0))     = C 0
simplyfy (Mul (C 0) x)     = C 0
simplyfy (Mul x (C 1))     = simplyfy x
simplyfy (Mul (C 1) x)     = simplyfy x
simplyfy (Pow _ 0)         = C 1
simplyfy (Pow x 1)         = simplyfy x
simplyfy (C x)             = C x
simplyfy Var               = Var
simplyfy (Mul x y)         = Mul (simplyfy x) (simplyfy y)
simplyfy (Add x y)         = Add (simplyfy x) (simplyfy y)
simplyfy (Pow x k)         = Pow (simplyfy x) k
