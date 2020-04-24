program P14715
    implicit none
    integer :: energy, factor_count
    integer :: i

    read (*, *) energy
    factor_count = 0
    do i = 2, energy - 1
        do while (mod(energy, i) == 0)
            energy = energy / i
            factor_count = factor_count + 1
        end do
    end do

    if (factor_count == 0) then
        write (*, '(I0)') 0
    else
        write (*, '(I0)') ceiling(log(real(factor_count)) / log(2.0))
    end if
end program P14715