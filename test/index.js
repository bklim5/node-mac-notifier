"use strict";

const MacNotification = require('bindings')('Notification').MacNotification
const assert = require('assert');

describe('Mac Notification', () => {
  it('should require an options argument', () => {
    assert.throws(() => {
      let notification = new MacNotification();
    });
  });
  
  it('should have an ID', () => {
    let id = 'really-long-string-identifying-this-uniquely';
    let notification = new MacNotification({id});
    assert.equal(notification.id, id);
  });
  
  it('should have a title', () => {
    let title = 'Hello OS X!';
    let notification = new MacNotification({title});
    assert.equal(notification.title, title);
  });
  
  it('should have a body', () => {
    let body = "This is a body"
    let notification = new MacNotification({body});
    assert.equal(notification.body, body);
  });
  
  it('should have a canReply field', () => {
    let canReply = true;
    let notification = new MacNotification({canReply});
    assert.equal(notification.canReply, canReply);
  });
});
