program P1041
    implicit none
    integer(8) :: size
    integer(8) :: top, bottom, front, back, left, right
    integer(8) :: min_point, min_edge, min_face
    read *, size
    read *, top, right, front, back, left, bottom
    min_face = min(top, bottom, front, back, left, right)
    min_edge = min(top + front, top + back, top + left, top + right, &
        bottom + front, bottom + back, bottom + left, bottom + right, &
        front + left, front + right, &
        back + left, back + right)
    min_point = min(top + front + left, top + front + right, &
        top + back + left, top + back + right, &
        bottom + front + left, bottom + front + right, &
        bottom + back + left, bottom + back + right)
    if (size == 1) then
        write (*, '(I0)') top + bottom + front + back + left + right &
            - max(top, bottom, front, back, left, right)
    else
        write (*, '(I0)') min_point * 4 &
            + min_edge * 4 + min_edge * (size - 2) * 8 &
            + min_face * (size - 2) * 4 + min_face * (size - 2) * (size - 2) * 5
    end if
end program P1041