;; exo 1

(defun suc (ls)
  (let ((o(car ls)))
    (dolist (x (cdr ls) t)
      (if (= 1 (abs (- o x)))
        (setf o x)
        (return-from suc nil) ;; return-from permet de sortir de la boucle et d'aller vers la boucle donner en agrument (ici suc)
    )

  )
))

(defun suc (ls)
	(do ((ls1 (cdr ls) (cdr ls1)) (o (car ls) (car ls1))) ((not ls1) t)
		(if (/= 1 (abs(- o (car ls1))))
		(return nil ))))


(defun diff-recur (lst)
	(cond((= (length lst ) 1) T) ;; comme un switch
		((not (= (car (cdr lst)) (+ (car lst) 1 ))) nil)
		(t (diff-recur (cdr lst))))))

;; exo2

(defun square (x)
	(if (and (integerp x) (> x 0) (<= x 5))
		(format t "mauvais argument")
		(* x x)))

;; exo 3

(defun mystery (x y) (cond ((null y) nil)  ((eql (car y) x) 0) (t (let ((z (mystery x (cdr y )))) (and z (+ z 1 ))))))


(defun enigma (x) (cond ((null x ) NIL) (T (cond ((null (car x)) T) (T (enigma (cdr x)))))))



;;exo 4

(defun min-max (ls)
	(list (apply #'min ls)
	      (apply #'max ls)))


(defun min-max (ls)
	(let ( (x 0) (y 0) )
	(setf x (apply #'min ls ))
	(setf y (apply #'max ls ))
	(list x y)))



;;exo 5

(defun maxi (ls)
  (* (apply #'max ls) (apply #'max (remove (apply #'max ls) ls))))

(defun maxi (ls)
	(let ( (x 0) (y 0))
	   (setf x (apply #'max ls))
	   (setf ls (remove (apply #'max ls) ls))
	   (setf y (apply #'max ls))
	   (* x y)
  )
)


;;exo 6

(defun rever (ls)
  (if (null ls)
    nil
    (append (rever (cdr ls )) (list (car ls)))
) )

(defun rever (ls)
  (let ((ace nil))
    (dolist (elt ls)
      (push elt ace))))


;;exo 7

(defun egalite (a b)
  (if (and (numberp a) (numberp b))
        (equal a b)
        (eql a b)
))

(defun my-equal (x y)
    (cond ( (and (numberp x ) (numberp y )) (= x y))
          (  (and (sumbolp x ) (symbolp y )) (eql x y))
          ( (and (consp x ) (consp y))
          (and (my-equal (car x) (car y)) (my-equal (cdr x) (cdr y))))
          (t nil )))


;; consp x --> on est certain que c'est une liste non vide
