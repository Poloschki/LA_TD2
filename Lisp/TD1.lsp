(defun exo2(list)(car(cdr(cdr(cdr list)))))

(defun exo3(a b ) (if (> a b) a b ))
(exo3 4 5)


(defun exo4(ls) (if ls (or (listp (car ls)) exo4(cdr ls))))
(exo4 '(5 54 4)) >> T
(exo4 (+ 5 6)) >> nil

(defun exo5AI(entier) (if (> entier 0) (progn (format t ".") (exo5AR(- entier 1) ))))

(defun exo5AR(entier)
  (do ((i 0 (+ i 1))) ((= i entier) 'done')
  (format t ".")
  )
)

(defun exo5BI (ls)
  (let ((recu 0))
    (dolist (obj ls)
      (if(eq (car ls) 'a)
        (setf recu (+ recu 1))
      )
    )
    (format t "~A"recu)
  )
)


(defun exo5BR (ls)
  (
    (let ((compt 0))
      if (ls)
        (
          progn
            (+ compt 1)
            (exo5BR (car ls))
          )
      )
  )
)

;; exo 5 
(defun a-rep(ls)
	(do ((ls1 ls (cdr ls1))
		(n 0 (+ n (if (eq (car ls1) 'a) 1 0 ))))
		((not ls1) ) 'done))

(defun a-rec (ls) (if ls (+ (if (eq (car ls) 'a) 1 0) (a-rec (cdr ls )))0))


L'exo 6 
enigme retourne T si X contient nil sinon nil

mystere 
1) condition (Y est nill) -> nil 
2) si X= (car Y) ->0 
3) Z = (mystere X (cdr Y))
Renvoi la position de X dans la liste Y


L'exo7
(defun summit (lst)
(apply #'+ (remove nil lst))) ;; le reùove n'enregistre pas la valeur

;; pas de critère d'arrêt 
(defun summit (lst)
	(if lst
		(+ (if (not (null (car lst))) (car lst) 0 (summit (cdr lst )))
		0
	)
)


