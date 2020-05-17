program P1407
    implicit none
    integer(8) :: a, b
    integer(8) :: sum
    integer :: shift = 0
    read *, a, b
    a = a - 1
    sum = b - a
    a = rshift(a, 1)
    b = rshift(b, 1)
    do while (b > 0)
        sum = sum + lshift(b - a, shift)
        a = rshift(a, 1)
        b = rshift(b, 1)
        shift = shift + 1
    end do
    write (*, '(I0)') sum
end program P1407
