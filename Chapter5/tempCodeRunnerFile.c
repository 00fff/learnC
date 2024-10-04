    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? "" : "");
        printf("\n");