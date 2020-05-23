program P1015
    implicit none
    integer :: n, i, j
    integer, dimension(50) :: array, result
    integer, dimension(1) :: min
    do i = 1, 50
        array(i) = 1001
    end do
    read *, n
    read *, (array(i), i = 1, n)
    j = 0
    do i = 1, n
        min = minloc(array)
        result(min(1)) = j
        j = j + 1
        array(min) = 1001
    end do
    do i = 1, n
        write (*, '(I0, X)', advance='no') result(i)
    end do
end program P1015g