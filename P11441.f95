program P11441
    implicit none
    integer :: size
    integer, dimension(0:100000) :: partial_sum
    integer :: queries
    integer :: start, end
    integer :: i

    read *, size
    read *, (partial_sum(i), i = 1, size)

    do i = 1, size
        partial_sum(i) = partial_sum(i) + partial_sum(i - 1)
    end do

    read *, queries
    do i = 1, queries
        read *, start, end
        write (*, '(I0)') partial_sum(end) - partial_sum(start - 1)
    end do
end program P11441