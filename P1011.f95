program P1011
    implicit none
    integer :: cases, i
    integer(8) :: x, y, even, odd
    read *, cases
    do i = 1, cases
        read *, x, y
        odd = 2 * int(ceiling(sqrt(real(y - x)))) - 1
        even = int(ceiling(sqrt(real(4 * (y - x) + 1)))) - 1
        write (*, '(I0)') min(odd, even)
    end do
end program P1011