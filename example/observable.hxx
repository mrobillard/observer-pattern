
#include <vector>
#include <algorithm>

#include "Observer.hpp"

// implementation details.
//namespace detail {

/**
 * The Observer base class providing methods for adding and removing observers
 *
 * @note This class is an internal implementation detail
 *
 * @class ObservableBase
 */
template <class T>
class ObservableBase
{

public:

    /**
     * Virtual Destructor
     */
    virtual ~ObservableBase ()
    {
    }

protected:

    /**
     * Vector of Observer Pointers
     */
    typedef typename std::vector<IObserver<T> * > ObserverVector;

    /**
     * List of Observers
     */
    ObserverVector m_observers;

protected:

    /**
     * Returns Vector of Observer Pointers
     *
     * @return Vector of Observer Pointers
     */
    ObserverVector GetObservers () const
    {
       return m_observers;
    }

public:

    /**
     * Adds an observer to the list of Observers
     *
     * @param observer : Observer to be added
     */
    void AddObserver ( Observer<T> * observer )
    {
        m_observers.push_back ( observer );
    }

    /**
     * Removes observer from list. This method creates a copy of the list to
     * iterate through to protect against a dead lock condition of removing
     * an observable object during a callback
     *
     * @param observer : Observer to be removed from list
     */
    void RemoveObserver ( Observer<T>* observer )
    {
        typename ObserverVector::iterator iter = std::find ( m_observers.begin (),
                                                    m_observers.end (),
                                                    observer );

        if ( iter != m_observers.end () )
        {
            m_observers.erase ( iter );
        }

    }

};

//} // namespace detail

/**
 * This class is extends the base of observable to include the functionality
 * of adding and removing observers from the list and add the notification
 * mechanism. Two forms of this class exist, one that takes an argument and
 * one that does not. This implementation takes an argument for notification.
 *
 * @class COvservable
 */
template <class T>
class Observable : public ObservableBase<T>
{

protected:

    /**
     * This method notifies the observers, additionally passing through
     * the event structure.
     *
     * @param arg : Event Information
     */
    void NotifyObservers ( T arg )
    {
        //
        // Make Copy of Observer List to protect against removing a listener while iterating.
        //
        typename ObserverVector observersCopy = GetObservers();

        for ( ObserverVector::iterator i = m_observers.begin ();
             i != m_observers.end();
             i++ )
        {
            (*i)->Notify ( this, arg );
        }
    }

};

/**
 * Void template for the Observable class that does not take an event
 * structure. This class simply
 *
 * @class CObservable
 */
template <>
class Observable<void> : public ObservableBase<void>
{

protected:

    /**
     * This method iterates through the list of observers and calls notify
     * on them.
     */
    void NotifyObservers ()
    {
        //
        // Make Copy of Observer List to protect against removing a listene
        // while iterating.
        //
        ObserverVector observersCopy = GetObservers ();

        for ( ObserverVector::iterator i = observersCopy.begin ();
             i != observersCopy.end ();
             i++ )
        {
            (*i)->Notify ( this );
        }

    }
};
