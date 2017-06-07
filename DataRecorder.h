#ifndef DATARECORDER_H_INCLUDED
#define DATARECORDER_H_INCLUDED
// Suèelje za sve sakupljaèe podataka
class DataRecorder{
  public:
    // Postavi broj oèitavanja podataka
    void  setNoReads(int nr) { mNoReads = nr; }
    virtual ~DataRecorder() {}

  protected:
    int mNoReads = -1;
};
#endif // DATARECORDER_H_INCLUDED
