#ifndef OBSERVER_HPP__
#define OBSERVER_HPP__

// foward declare CObservable
template <class T>
class Observable;

/**
 * Interface for receiving notification of changes to an {@link CObservable}.
 *
 * @note The class that inherits from Observer needs to implement the
 * Notify method. This will be called by the subject.
 *
 * @author Matthew Robillard
 *
 * @class Observer Listens for events
 */
template <class T>
class Observer
{
    /**
     * Virtual Destructor
     */
    virtual ~Observer ()
    {
    }

    /**
     * Fires an event ( Notifies observers )
     *
     * @param observable - Object that is firing event
     */
    virtual void Notify ( Observable<T> * observable, T arg ) = 0;

};

/**
 * Specialization of @c IObserver interface for
 * empty @c void argument type.
 */
template <>
class Observer<void>
{
	/**
	 * Virtual Destructor
	 */
	virtual ~Observer ()
	{
	}

	/**
	 * Fires an event ( Notifies observers )
	 *
	 * @param observable - Object that is firing event
	 */
	virtual void Notify ( Observable<void> * observable ) = 0;

};

#endif // OBSERVER_HPP__
