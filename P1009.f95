program P1009
    implicit none
    integer :: cases, i
    integer :: a, b, mul, j
    read *, cases
    do i = 1, cases
        read *, a, b
        mul = a
        do j = 2, b
            mul = mod(mul * a, 10)
        end do
        write (*, '(I0)') mod(mul + 9, 10) + 1
    end do
end program P1009