#ifndef RETURNIF_H
#define RETURNIF_H

#define RETURN return;
#define RETURN_ARG(exp) return (exp);

#define RETURN_IF(exp)  \
    if(exp) return;

#define RETURN_ARG_IF(exp, ret) \
    if(exp) return ret;

#endif // RETURNIF_H
