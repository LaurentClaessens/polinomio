
/*DEFINIZIONE METODI E COSTRUTTORI DI SMARTP***********************************************************************************************/

/*COSTRUTTORE*/
smartp::smartp(Monomial *p) : pMonomial(p) {
    if (pMonomial) pMonomial->riferimenti++;
}

/*COSTRUTTORE DI COPIA*/
smartp::smartp(const smartp &s) : pMonomial(s.pMonomial){
    if (pMonomial) //se ho inizializzato uno smartp con uno smartp con pMonomial non nullo
        pMonomial->riferimenti++; //incremento i riferimenti che pMonomialano a quel pMonomial
}

/*DISTRUTTORE*/
smartp::~smartp(){
    if (pMonomial) { //se lo smartp pMonomiala a un pMonomial non nullo
        pMonomial->riferimenti--; //decrementa i riferimenti a quel pMonomial
        if (pMonomial->riferimenti==0) //se i riferimenti sono 0 non pMonomiala nessuno al pMonomial
            delete pMonomial; //cancellalo
    }
}

/*ASSEGNAZIONE*/
smartp& smartp::operator=(const smartp& s){
    if (this != &s) {
        Monomial *t = pMonomial;
        pMonomial = s.pMonomial;
        if (pMonomial) pMonomial->riferimenti++;
        if (t) {
            t->riferimenti--;
            if (t->riferimenti == 0) delete t;
        }
    }
    return *this;
}

smartp::is_valid(){ 
    if (pMonomial) return true;
    return false;
}

void smartp::make_zero() { pMonomial=0; }

Monomial& smartp::operator*() const{
    return *pMonomial; //*smartp = *pMonomial ora;
}

Monomial* smartp::operator->() const{
    return pMonomial; //smartp->membro = pMonomial->membro ora;
}

bool smartp::operator==(const smartp& p) const{
    return pMonomial==p.pMonomial; 
}

bool smartp::operator!=(const smartp& p) const{
    return !(pMonomial==p.pMonomial);
}
