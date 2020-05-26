program P14583
    implicit none
    real(8) :: h, v, t, width, height
    read *, h, v
    t = atan2(v, h) / 2
    width = h / cos(t) / 2
    height = sqrt(h * h + v * v) * sin(t)
    write (*, '(F0.2)') width, height
end program P14583