program P13116
    implicit none
    integer :: t, a, b
    read *, t
    do while (t > 0)
        read *, a, b
        do while (a /= b)
            if (a > b) then
                a = rshift(a, 1)
            else
                b = rshift(b, 1)
            end if
        end do
        write (*, '(I0)') a * 10
        t = t - 1
    end do
end program P13116