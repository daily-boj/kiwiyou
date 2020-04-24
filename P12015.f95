program P12015
    implicit none
    integer :: length
    integer, dimension(1000000) :: sequence, rearranged
    integer :: i
    integer :: size
    integer :: low, mid, high
    read (*, *) length
    read (*, *) (sequence(i), i = 1, length)
    size = 1
    rearranged(1) = sequence(1)
    do i = 2, length
        if (rearranged(size) < sequence(i)) then
            size = size + 1
            rearranged(size) = sequence(i)
        else if (rearranged(size) > sequence(i)) then
            low = 1
            high = size
            do while (low < high)
                mid = (low + high) / 2
                if (rearranged(mid) < sequence(i)) then
                    low = mid + 1
                else
                    high = mid
                end if
            end do
            mid = (low + high) / 2
            rearranged(mid) = sequence(i)
        end if
    end do
    write (*, '(I0)') size
end program P12015