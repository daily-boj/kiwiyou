program P10464
    implicit none
    integer :: cases
    integer :: s, f
    integer :: i
    read *, cases
    do i = 1, cases
        read *, s, f
        s = s - 1
        if (iand(s, 3) == 1) then
            s = 1
        else if (iand(s, 3) == 2) then
            s = ior(s, 1)
        else if (iand(s, 3) == 3) then
            s = 0
        end if
        if (iand(f, 3) == 1) then
            f = 1
        else if (iand(f, 3) == 2) then
            f = ior(f, 1)
        else if (iand(f, 3) == 3) then
            f = 0
        end if
        write (*, '(I0)') ieor(f, s)
    end do
end program P10464