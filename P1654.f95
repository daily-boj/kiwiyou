program P1654
    implicit none

    integer :: having, needed
    integer, dimension(10000) :: length
    integer(8) :: low, mid, high
    integer(8) :: computed
    integer :: i

    read (*, *) having, needed
    read (*, *) (length(i), i = 1, having)

    low = 1
    high = 2147483647
    do while (low <= high)
        mid = (low + high) / 2
        computed = 0
        do i = 1, having
            computed = computed + (length(i) / mid)
        end do
        if (computed >= needed) then
            low = mid + 1
        else if (computed < needed) then
            high = mid - 1
        end if
    end do

    write (*, '(I0)') ((low + high) / 2)
end program P1654