program P1834
    implicit none
    integer :: divisor, i
    integer(8) :: sum, adder
    read *, divisor
    sum = 0
    adder = divisor + 1
    do i = 2, divisor
        sum = sum + adder
        adder = adder + divisor + 1
    end do
    write (*, '(I0)') sum
end program P1834