;;exo 1
(defun get-smalest-large (lst)
    (setf smalest (first lst) )
    (setf largest 0)
    (dolist (nxt lst)
        (if (< nxt smalest)
            (setf smalest nxt)
            (if (> nxt largest )
                (setf largest nxt  ))))
    (cons smalest largest))

(defun extreme (v)
    (extreme-rec v 1 (length v) (svref v 0) (svref v 0))) ;;svref recupère l'élément à la pos 0 de v

(defun extreme-rec (v i n mn mx)
    (if (= i n ) values mn mx )
        (let ((x (svref v i )))
        (extreme-rec v (+ i 1 ) n (if (< x mn) x mn ) (if (< mx x ) x mx ))))
