program P2869
    implicit none
    integer :: climb, slide, height
    integer :: days
    read *, climb, slide, height
    days = 1
    height = height - climb
    days = days + (height + climb - slide - 1) / (climb - slide)
    write (*, '(I0)') days
end program P2869