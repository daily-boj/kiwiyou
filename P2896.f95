program P2896
    implicit none
    real :: orange, apple, pine
    real :: i, j, k
    integer :: it, max

    real, dimension(3, 4) :: result

    read (*, *) orange, apple, pine
    read (*, *) i, j, k

    result(1, 1) = 0
    result(1, 2) = apple - orange * j / i
    result(1, 3) = pine - orange * k / i
    result(1, 4) = orange / i

    result(2, 1) = orange - apple * i / j
    result(2, 2) = 0
    result(2, 3) = pine - apple * k / j
    result(2, 4) = apple / j

    result(3, 1) = orange - pine * i / k
    result(3, 2) = apple - pine * j / k
    result(3, 3) = 0
    result(3, 4) = pine / k

    max = 1
    do it = 1, 3
        if (result(it, 1) < 0 .or. result(it, 2) < 0 .or. result(it, 3) < 0) then
            result(it, 4) = 0
        end if
        if (result(max, 4) < result(it, 4)) then
            max = it
        end if
    end do

    write (*, *) result(max, 1), result(max, 2), result(max, 3)
end program P2896